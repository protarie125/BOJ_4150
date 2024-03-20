#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll n;

string Add(const string& a, const string& b) {
  auto va = vl(a.length(), 0);
  for (auto i = 0; i < a.length(); ++i) {
    va[i] = a[a.length() - 1 - i] - '0';
  }

  auto vb = vl(b.length(), 0);
  for (auto i = 0; i < b.length(); ++i) {
    vb[i] = b[b.length() - 1 - i] - '0';
  }

  auto ret = vl(max(va.size(), vb.size()));
  auto j = 0;
  auto carry = 0;
  while (j < va.size() && j < vb.size()) {
    auto x = va[j] + vb[j] + carry;
    carry = x / 10;
    x %= 10;

    ret[j] = x;
    ++j;
  }

  while (j < va.size()) {
    auto x = va[j] + carry;
    carry = x / 10;
    x %= 10;

    ret[j] = x;
    ++j;
  }

  while (j < vb.size()) {
    auto x = vb[j] + carry;
    carry = x / 10;
    x %= 10;

    ret[j] = x;
    ++j;
  }

  if (0 < carry) {
    ret.push_back(carry);
  }

  auto oss = ostringstream{};
  for (auto it = ret.rbegin(); it != ret.rend(); ++it) {
    oss << *it;
  }

  return oss.str();
}

string Fibo(const ll& n, const string& f0, const string& f1) {
  if (0 == n) {
    return f0;
  }

  if (1 == n) {
    return f1;
  }

  const auto& sum = Add(f0, f1);
  return Fibo(n - 1, f1, sum);
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  cout << Fibo(n, "0", "1");

  return 0;
}