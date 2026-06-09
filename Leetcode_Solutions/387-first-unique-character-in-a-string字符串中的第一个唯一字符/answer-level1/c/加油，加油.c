### 解题思路
很好的思路，代替了java的HashMap

```c
//创建一个辅助数组nums[26]，记录26个英文字母的出现次数  两次遍历即可   超越97.6
int firstUniqChar(char * s){
    int length = strlen(s);
    if(length<=0) return -1;
    if(length==1) return 0; 
    int nums[26] = {0};
    //先统计个数
    int index;
    for(int i=0; i<length; i++){
        index = s[i]-'a';
        ++nums[index];
    }
    //再次遍历 找出个数为1的第一个字符
    for(int i=0; i<length; i++){     //注意遍历有序的字符数组，因为要第一个
        index = s[i]-'a';
        if(nums[index]==1)
            return i;
    }
    return -1; 
}
```