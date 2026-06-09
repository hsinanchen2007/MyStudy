滑动窗口一般用于解决找出查找满足一定条件的**连续区间**的性质（长度等）的问题。对应的题型常常是找“子串”。
一般右指针自然向右滑动，左指针有条件右滑。找到左指针的滑动条件即可以得到题解。

```
int max(int a, int b){
    return (a>b)?a:b;
}

int equalSubstring(char * s, char * t, int maxCost){
    int right = 0;
    int left = 0;
    int sLen = 0;
    int curCost = 0;

    while (right < strlen(s)){
        curCost += abs(s[right] - t[right]);
        while (curCost > maxCost && left < right){
            curCost -= abs(s[left] - t[left]);
            left++;
        }

        if (curCost <= maxCost){
            sLen = max(sLen, right - left + 1);
        }
        right++;
    }
    return sLen;
}
```
解答完题目后，我发现我的速度并别人慢很多。于是找到下面的答案。发现有几个判断并没有存在的必要。我的细节的思维敏捷性上，还是差“聪明人”一等。
```
int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int equalSubstring(char * s, char * t, int maxCost){
    int result = 0;
    int left = 0;
    int right = 0;
    int sLen;
    int curCost = 0;
    
    sLen = (int)strlen(s);
    while (right < sLen) {
        curCost = curCost + abs(s[right] - t[right]);
        right++;

        while (curCost > maxCost) {
            curCost = curCost - abs(s[left] - t[left]);
            left++;
        }

        result = Max(result, right - left);
    }

    return result;
}
```
