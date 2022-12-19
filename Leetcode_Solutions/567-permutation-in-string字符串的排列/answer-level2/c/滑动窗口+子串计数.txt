![image.png](https://pic.leetcode-cn.com/56b7878c3ae87f3199a9c64c1f9f5b0c44adec9bfeae20c211090ef48fcdcab4-image.png)

```
bool checkInclusion(char * s1, char * s2){
    if(s1 == NULL || s2 == NULL) {
        return false;
    }
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    if(l1 > l2) {
        return false;
    }
    int tmp[256] = {0};
    int cnt = l1;//s1字符的总数
    int i = 0;
    while(i < l1) {
        tmp[s1[i]]++;//记录s1各字符的数量
        i++;
    }

    i = 0;
    int l = 0;//窗口的起始位置
    while(i < l2 && cnt > 0) {//cnt为0则表明s1中所有的字符都在s2的连续子串中找到
        if(tmp[s2[i]] == 0) {//s2[i]字符在s1中不存在或者窗口[l,i-1]的子串中该字符的数量已经满了
            while(s2[l] != s2[i]) { //更新窗口左边l，直到s2[l] == s2[i]，这样就可以把s2[l]的字符占位让给s[i]，
                tmp[s2[l]]++;       //如果l==i则表明该字符不在s1中，之前的子串也就没有用了，在循环的过程中tmp[s2[l]]++
                l++;                //已经把之前的子串计数还原了，cnt++把需要匹配的字符总数给还原了
                cnt++;
            }
            l++;//不管在之前统计的子串中有没有找到l都需要更新，找到的话是把自己的占位让出来，没找到则表明s2[i]不在s1中
        } else {//s2[i]在s1中存在，且当前的窗口[l,i-1]中包含的字符没有超出s1中该字符的数量，继续更新，需要匹配的字符
            cnt--;   //数量cnt减1,子串计数对应字符减1
            tmp[s2[i]]--;
        }
        i++;
    }

    return cnt == 0;
}
```
