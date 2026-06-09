假设这个树不是之字形，而是从左向右的树，即
1
| \
2   3 
|\  |\ 
4 5 6 7
........
这样，那我们看一下样例，当label=14时，我们倒序找一下路径，这个很好找，不停除以2就行了
即[14,7,3,1]，然后再颠倒一下就找到路径了
即[1,3,7,14]

比如2,3是对称的，5,6是对称的，4,7是对称的。这里有个规律，就是每层对称的两个数加起来是一个确定的数字，不难发现，这个数和这个层次有关。

但此题是“之”字型树，我们只需要将对应位置的树取成对称的树就可以了。哪些位置呢？ 不难发现，从label后一个数开始，隔一个位置。
[14,7,3,1]中，要取对称的数为[7,1]，取对称后即[4,1]。
所以最后结果为[14,4,3,1]，再颠倒即可。

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // Make sure the level of the label
        unsigned level=1;
        while(label>pow(2,level)-1){
            level++;
        }
        
        int* level_sysmetry_sum=new int[level+1];
        level_sysmetry_sum[1]=2;
        for(unsigned i=2;i<=level;i++)
            level_sysmetry_sum[i]=2*level_sysmetry_sum[i-1]+1;
        vector<int>ans;
        while(label>=1){
            ans.push_back(label);
            label=label/2;
        }
        if(ans.size()>1){
            unsigned current_level=level-1;
            for(unsigned i=1;i<ans.size();i+=2){
                ans[i]=level_sysmetry_sum[current_level]-ans[i];
                current_level-=2;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
