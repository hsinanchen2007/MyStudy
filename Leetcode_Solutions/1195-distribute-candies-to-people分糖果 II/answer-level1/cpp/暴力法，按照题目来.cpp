```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
	vector<int> vec;
	vec.resize(num_people);
	int k = 1;
	int i = 0;
	while (candies != 0)
	{
		vec[(i++) % num_people] += (candies - k) >= 0 ? k : candies;
		candies -= (candies - k) >= 0 ? k++ : candies;
	}
	return vec;
}

int main()
{
	vector<int> vec = distributeCandies(10, 3);
	for_each(vec.begin(), vec.end(), [](const auto &x) {cout << x << " "; });
	
	return 0;
}
```
按照题目一步步去做就可以了，虽然比不上算术法