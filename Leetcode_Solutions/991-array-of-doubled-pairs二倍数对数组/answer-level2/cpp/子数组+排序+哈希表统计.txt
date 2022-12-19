# 
`1.将数组分成两个子数组，将为负数的元素取正数后存入aVecs数组，将为正数的元素存入bVecs数组`
`2.统计aVecs, bVecs两个数组的个数，若不为偶数直接返回错误`
`3.取其中一个数组，从小到大排序，然后遍历数组，利用unordered_map来统计个数`
`4.遍历数组，由于先遍历的元素数值小，可直接查找是否存在当前值二倍的元素，不存在则返回错误，将统计过的元素数自减`
`5.对另一个数组重复3、4操作，最终返回值是对两个数组相关操作的与值`
# 

```
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        vector<int> aVecs, bVecs;
        
        for(int a: A)
        {
            if(a < 0)
                aVecs.push_back(0 - a);
            else if(a > 0)
                bVecs.push_back(a);
        }
        
        int aLen, bLen;
        if((aLen = aVecs.size()) % 2 != 0 || (bLen = bVecs.size()) % 2 != 0)
            return false;
        
        function<bool(vector<int>&, int)> isMeet = [](vector<int>& vec, int len)
        {
            sort(vec.begin(), vec.end(), [](int a, int b){ return a < b; });
            
            unordered_map<int, int> hashMap;
            for(int a: vec)
                hashMap[a]++;
            
            for(int a: vec)
            {
                if(hashMap[a] != 0)
                {
                    if(0 == hashMap[a * 2])
                        return false;
                    hashMap[a]--, hashMap[a * 2]--;
                }
            }

            return true;
        };
        
        return isMeet(aVecs, aLen) && isMeet(bVecs, bLen);
    }
};
```