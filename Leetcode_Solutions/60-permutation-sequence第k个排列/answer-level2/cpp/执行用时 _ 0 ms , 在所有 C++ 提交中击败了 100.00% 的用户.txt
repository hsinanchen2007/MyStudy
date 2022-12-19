### 解题思路
此处撰写解题思路
连续的1-n 给定后全排列也是定的 当然可以将所有的全排列都求出，但费时，我们可以每次根据 k/（n-1)! 找出一个坐标 之后将set中的这个数清除掉，set是根据大小排列的，每次从set中取出我们的坐标值 不断的找第一个数就找到了所有的

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        set<int> leftnum;
        string min;
        for(int i=1;i<=n;i++) leftnum.insert(i);
        set<int>::iterator beginit=leftnum.begin();
        vector<int> mul;
        int record=1;
        for(int i=1;i<=n;i++){
            record=record*i;
            mul.push_back(record);
        }
        int divnum;
        for(int i=n-2;i>=0;i--){
            divnum=(k-1)/mul[i];
            k=k-divnum*mul[i];
            for(int j=0;j<divnum;j++) beginit++;
            int findnum=*beginit;
            leftnum.erase(beginit);
            beginit=leftnum.begin();
            min+='0'+findnum;
        }
        min+='0'+*beginit;
        return min;
    }
};
```