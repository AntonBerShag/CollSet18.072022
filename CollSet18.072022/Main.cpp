#include <iostream>
#include <vector>
#include <unordered_set>//дл€ матиматических множиств, дл€ регул€рного поиска
#include <type_traits>
#include <string>
using namespace std;

struct Coord {
	int a;
	int b;
	bool operator==(const Coord& other) const {
		return a == other.a && b == other.b;
	}
};

namespace std {
	template<>
	struct less<Coord> {
		bool operator()(const Coord& a, const Coord& b) const {
			return (a.a < b.b) && (a.b < b.b);
		}
	};
	
	template<>
	struct hash<Coord> {
		size_t operator()(const Coord& coord) const {
			return (hash<int>()(coord.a)<<1) ^
				hash<int>()(coord.b);
		}
	};
}

class Unit {
public:
	Unit(string name, string fraction, int size) {
		this->name = name;
		this->fraction = fraction;
		this->size = size;
	}
	virtual ~Unit();
private:
	string name;
	string fraction;
	int size;
};

int main() {
	unordered_set<Coord> set{
		{1, 2},
		{1, 2},
		{3, 4},
		{5, 6}
	};
	for (auto&& [a, b] : set)
	{
		cout << a << " " << b << '\n';
	}
	set.find({3, 8});//возвращ€ет set.end()
				//если ничего не нашел
	set.size();
	//less<Coord>()(Coord(), Coord());
	set.insert({ 9, 12 });
	set.erase({ 5, 6 });
	set.contains({1, 2});

	unordered_set<Unit> unit{"√улдан", "ќрда", 14};

	return 0;
}