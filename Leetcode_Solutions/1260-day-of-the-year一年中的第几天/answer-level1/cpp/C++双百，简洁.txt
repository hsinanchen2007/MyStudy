### 解题思路
注意范围内的闰年除了1900外都是4的倍数，其他的没什么了

### 代码

```cpp
class Solution {
public:
    int dayOfYear(string date) {
        int year=stoi(date.substr(0,4)),month=stoi(date.substr(5,2)),day=stoi(date.substr(8)),ans=0,i=month;
        int arr[11]={31,28,31,30,31,30,31,31,30,31,30};
        while(--i)ans+=arr[i-1];
        return ans+day+(year%4==0&&year!=1900&&month>2);
    }
};
```