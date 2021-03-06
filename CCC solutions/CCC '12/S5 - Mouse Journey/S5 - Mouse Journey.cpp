#include <iostream>
#include <vector>
#include <map>

typedef std::pair<int, int> PII;

bool find(std::vector<PII> cats, PII element) {
	for (auto cat : cats) {
		if (cat.first == element.first && cat.second == element.second) {
			return true;
		}
	}return false;
}

std::map <PII, int> bfs(int r, int c, std::vector<PII> cats) {
	PII start = { 0,0 };
	std::vector<PII> qu = { start };
	std::map <PII, int> paths;
	paths[start] = 1;

		while (!qu.empty()) {
		PII node = qu[0];
		qu.erase(qu.begin());

		int d[4] = { 0,1,1,0 };
		for (int i = 0; i < 4; i += 2) {
			int y = node.first + d[i], x = node.second + d[i + 1];
			PII child = { y,x };
			if (find(cats, child)) { // next is in cats
				continue;
			}
			else if (x < c && y < r) {
				if (paths[child] != 0) { // check if {y,x} in paths / set {y,x} to 0
					paths[child] += paths[node];
				}
				else {
					qu.push_back(child);
					paths[child] = paths[node];
				}
			}
		}
	}return paths;
}
int main() {
	int r, c, n, x, y;
	std::vector<PII> cats;
	std::cin >> r >> c >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		cats.push_back({ x-1,y-1 });
	}
	std::map <PII, int> paths = bfs(r, c, cats);
	std::cout << paths[{r - 1, c - 1}];
}