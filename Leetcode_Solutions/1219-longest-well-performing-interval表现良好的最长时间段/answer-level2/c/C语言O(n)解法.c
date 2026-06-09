### 解题思路
数组从前向后遍历
假设到索引idx1处不困的数量比困的数量多m，而且是第一次出现，记当前索引到哈希表hash[m] = idx1
下次遇到索引idx2不困的数量为m-1，则m-1-m=-1，即困的数量刚好大于不困的数量，从而idx2-idx1即
为表现良好的最大区间，一次遍历即可求出最大的表现良好天数

### 代码

```c


int longestWPI(int* hours, int hoursSize){
    int ret = 0;
    int hash[10001] = {0};
    int sum = 0;
    int tmp = 0;
    int i = 0;
    
    memset(hash, 0xFF, sizeof(hash));
    
    for (i = 0; i < hoursSize; i++)
    {
        sum += hours[i] > 8 ? -1 : 1;
        if (sum >= 0)
        {
            if (-1 == hash[sum])
            {
                hash[sum] = i;
            }
            
            if (-1 != hash[sum+1])
            {
                tmp = i-hash[sum+1];
                ret = tmp > ret ? tmp : ret;
            }
        }
        else
        {
            ret = i+1;
        }
    }
    
    return ret;
}


```