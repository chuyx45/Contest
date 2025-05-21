#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <set>
#include <list>
#include <algorithm>
#include <sstream>
#include <optional>
#include <stdexcept>
#include <stack>

// cd /mnt/c/Users/jose/Documents/documentos_dell/Contest/

using namespace std;

#define rep(i, a, b) \
	for(int i=int(a); i<int(b); ++i)

#define trv(c, it) \
	for(auto it=(c).begin(); it!=(c).end(); ++it)

#define repeat(b) \
	for(int _i=0; _i<int(b); ++_i)

#define repeati(i, b) \
	for(int i=0; i<int(b); ++i)

#define LMAX LONGMAX
#define LONG_MA 1000000000 // 10^9

#define ca const auto
#define str string
#define vi vector<int>
#define vl vector<long>
#define vs vector<str>


template <typename T>
T read() {
	T t;
	cin >> t;
	return t;
}
#define readi read<int>
#define reads read<str>
#define readl read<long>


template <typename T>
void print(const T&t) {
	cout << t << '\n';
}

vi readvi(int n) {
	vi arr(n);
	repeati(i, n) {
		arr[i] = readi();
	}
	return arr;
}

inline void no()  { cout << "NO\n";  }
inline void yes() { cout << "YES\n"; }
inline void check(const bool b) {
	if (b) {
		yes();
	}
	else {
		no();
	}
}


// binay_search;
//bool binay_search(vector<int>& arr, const int l, const int r, const int x);
//int binay_searchs(std::string& arr, const int l, const int r, const char x);

constexpr int toInt(const char x) noexcept {
	return (x + 1) - 'a';
}

constexpr bool sPair(const pair<char, int> a, const pair<char, int> b) { return a.first < b.first; }
constexpr bool bPair(const pair<char, int> a, const pair<char, int> b) { return a.first > b.first; }



int main() {
	//std::cout << std::numeric_limits<long long>::min() << '\n';
	ca r = readi();
	int n;
	int k;
	repeat(r) {
		n = readi();
		k = readi();
		vector<long long> arr(n);

		long long acc = 0;
		int ax = 0;
		long long in = std::numeric_limits<long long>::max();

		repeati(i, n) {
			ca x = read<long long>();
			acc += x;
			
			if (arr[ax] < x) {
				ax = i;
			}

			in = min(in, x);
			arr[i] = x;
		}

		arr[ax] = arr[ax] - 1;

		long long mmax = 0;
		repeati(i, n) {
			mmax = max(mmax, arr[i]);
		}
		if ((mmax - in) > k) {
			std::cout << "Jerry\n";
		}
		else if(acc % 2 == 0) {
			std::cout << "Jerry\n";
		}
		else {
			std::cout << "Tom\n";
		}


	}

	return 0;
}

bool binay_search(vector<int>& arr, const int l, const int r, const int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) {
			return true;
		}
		if (arr[mid] > x) {
			return binay_search(arr, l, mid - 1, x);
		}
		return binay_search(arr, mid + 1, r, x);
	}
	return false;
}

int binay_searchs(std::string& arr, const int l, const int r, const char x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		if (arr[mid] > x) {
			return binay_searchs(arr, l, mid - 1, x);
		}
		return binay_searchs(arr, mid + 1, r, x);
	}
	return -1;
}

str reverse(const str& a) {
	str b = a;
	for (int i = 0; i < a.size(); ++i) {
		b[b.size() - (i + 1)] = a[i];
	}
	return b;
}
int m_lex_compare(const str& a) {
	ca a_rev = reverse(a);
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > a_rev[i]) {
			return -1;
		}
		else if (a[i] < a_rev[i]) {
			return 1;
		}
	}
	return 0;
}

class pair_permut {
	int index_a = 0;
	int index_b = 1;
public:
	optional<pair<int, int>> get_next(const vi& a) {
		if (index_b >= a.size()) {
			++index_a;
			index_b = index_a + 1;
		}
		if (index_b >= a.size()) {
			return {};
		}
		pair<int, int> r(a[index_a], a[index_b]);
		++index_b;
		return r;
	}
};

int gcd(const int a, const int b) {
	int x = min(a, b);
	while (x >= 2) {
		if ((a % x) == 0 and (b % x) == 0) {
			return x;
		}
		--x;
	}
	return 1;
}

template <class T>
bool all_eq_t(/*iterator<T> it, const T val*/) {
	return true;
}

bool all_eq(const std::string& a) {
	const char c = a[0];
	for (ca x : a) {
		if (x != c) {
			return false;
		}
	}
	return true;
}