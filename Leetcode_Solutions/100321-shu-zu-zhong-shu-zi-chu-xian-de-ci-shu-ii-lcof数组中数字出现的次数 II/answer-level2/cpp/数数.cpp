该题仍然要利用抑或来进行分析
思路：
1.三个数相同，为1的位为3的倍数
2.我们逐位数出数组中该位为1的个数
    如果个数刚好是3的倍数，说明，唯一的那个数在该位上为0。
    如果个数不是3的倍数，说明，唯一的那个数在该位上为1。
遍历每一位之后我们可以得出唯一的那个数
```
int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i=0;i<31;i++){
        int count = 0;
        int bit = 1<<i;
        for(int a:nums){
            if((a&bit)==bit)
                count++;
        }
        if(count%3!=0)
            res|=bit;
    }
    return res;
}
```
