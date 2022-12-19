如果s[idx]在已经找到的子串中出现过，并且位置为j的话，则下次找的子串的起始位置从 j+1 开始，因为从j之前的位置开始的最大子串的长度就是从startpos开始到s[idx]前一个元素的长度。



int lengthOfLongestSubstring(char * s){
    if (s == NULL) {
        return 0;
    }

    int gmax = 0; // 记录全局最长的子串
    int subMax = 0;  // 记录局部子串的长度
    int idx = 0;
    int j = 0;
    int startpos = 0; // 从s数组的startpos位置开始遍历最大子串
    while(s[idx] != 0) {
        for (j = startpos; j < idx; j++) {
            if (s[j] == s[idx]) {
                break;
            }
        }

        if (j == idx) { // 说明s[idx]跟当前的子串中的元素都不一样
            subMax++;
        } else {
            if (gmax < subMax) {
                gmax = subMax;
            }

            subMax = subMax - (j - startpos + 1) + 1;
            startpos = j + 1; // 下一次遍历的子串从 j + 1 位置开始
            

        }

        idx++;
    }

    if (subMax > gmax) {
        gmax = subMax;
    }

    return gmax;
}