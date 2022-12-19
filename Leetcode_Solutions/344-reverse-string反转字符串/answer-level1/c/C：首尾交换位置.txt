思路：
首尾字符交换位置，交换到中间结束
交换这里可以直接用异或来做，不额外定义temp变量
交换的异或做法：很好记忆，右边始终相同，左边交替一次就好
a = a ^ b;
b = a ^ b;
a = a ^ b;
```
void reverseString(char* s, int sSize){
    for(int i = 0; i < sSize / 2; i++){
        s[i] = s[i] ^ s[sSize - i - 1];
        s[sSize - i - 1] = s[i] ^ s[sSize - i - 1];
        s[i] = s[i] ^ s[sSize - i - 1];
    }
    return;
}
```
