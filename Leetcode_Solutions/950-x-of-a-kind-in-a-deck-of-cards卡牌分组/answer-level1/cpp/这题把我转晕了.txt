### 解题思路
统计每个数出现的次数后，求所有次数间的最大公约数，如果公约数大于1并且整副牌的数量大于1则返回true；否则返回false

### 代码

```cpp
class Solution {
public:
    int gcd(int a,int b){
        int max=a>b?a:b;
        int min=a<b?a:b;
        while(max%min){
            int temp=min;
            min=max-(max/min)*min;
            max=temp;
        }
        return min;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int size=deck.size();
        int array[10001];
        int array1[10001];
        memset(array,0,sizeof(int)*10001);
        memset(array1,0,sizeof(int)*10001);
        int j=1;
        for(int i=0;i<size;i++){
            if(!array[deck[i]]){
                array[deck[i]]=j;
                j++;
            }
            array1[array[deck[i]]]++;
        }
        if(size==1){
            return false;
        }
        for(int i=1;i<j-1;i++){
            if(gcd(array1[i],array1[i+1])==1){
                return false;
            }
        }
        return true;
    }
};
```