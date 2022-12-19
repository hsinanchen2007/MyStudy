思想：采用双指针+滑窗, 循环每次移动right指针：
1、统计窗口内字符出现频度（arry）；
2、如果窗口内需替换字符数量超出k，则移动left指针；
3、滑窗长度计算（right - left + 1）;

滑窗内替换字符数量用GetReplayNum（int *arry）实现。两个变量，num等于滑窗内所有字符数量；max是频度最高的字符；num-max就是要替换的字符数量

#define  AC 26
// 获取滑窗arry中需要替换的字符数量
int GetReplayNum(int *arry)
{
    int num = 0;
    int max = 0;
    for (int i = 0; i < AC; i++) {
        num +=arry[i];
        max = arry[i] > max ? arry[i] : max;
    }
    return (num - max);
}
int characterReplacement(char * s, int k){
    if (s == NULL) {
        return 0;
    }
    int arry[AC] = {0};
    int left = 0;
    int right = 0;
    int len = strlen(s);
    int MAXL = 0;
    for (right = 0; right < len; right++) {
        arry[s[right] - 'A']++;        
        while (GetReplayNum(arry) > k) {  // 
            arry[s[left] - 'A']--;
            left++;
        }
        MAXL = (right - (left - 1)) > MAXL ? (right - (left - 1)) : MAXL;
    }
    return MAXL;
}