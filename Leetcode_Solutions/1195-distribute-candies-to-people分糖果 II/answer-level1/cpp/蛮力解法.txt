### 解题思路
用蛮力解此题，没超时，成绩还不错。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res( num_people, 0 );
        if ( candies <= 0 || num_people <= 0 )
            return res;

        int mark = 0;
        while ( candies > 0 ) {
            int circle = mark * num_people;
            for ( int i = 0; i < num_people; ++i ) {
                if ( candies >= circle + i + 1 ) {
                    res[i] += circle + i + 1;
                    candies -= circle + i + 1;
                }
				else if ( candies > 0 ) {
					res[i] += candies;
					candies -= circle + i + 1;
				}
                else
                    break;
            }
            ++mark;
        }

        return res;
    }
};
```