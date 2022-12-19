


extern bool equal(int* src, int* dest);
bool checkInclusion(char * s1, char * s2){
    //先将两个字符串的长度都计算出来
    int len = strlen(s1);
    int dest_len = strlen(s2);

    //如果原串比目的串长，则返回false,表示目的串中不可能存在原串的排列组合
    if (len > dest_len) {
        return false;
    }

    int src[26] = { 0 };
    int dest[26] = { 0 };

    //以s1的长度作为窗口的宽度，分别计算出s1和s2在该窗口宽度内的字符个数，通过hash的方式记录下来。
    for (int i = 0; i < len; i++) {
        src[s1[i] - 'a']++;
        dest[s2[i] - 'a']++;
    }

    //下面判断该窗口内，所有字符的个数是否相等
    for (int head = 0, tail = len; tail < dest_len; tail++, head++) {
        if (equal(src, dest)) {
            return true;
        }

        //将窗口向右滑动一格，然后再次比较src和dest里面的hash值是否相同
        //滑动的时候，将当前窗口宽度后面的一个字符hash到数组里面(计数加一)，将窗口左边的第一个字符在hash 结果里面去掉(计数减一)。
        //整个过程中不要变化src 源串的hash 值。
        dest[s2[tail] - 'a']++;
        dest[s2[head] - 'a']--;
    }

    //退出循环是，最后一次滑动窗口，没有在循环内得到验证，需要在循环外验证最后一次滑动串口后的src和dest的hash值是否相等。
    if (equal(src, dest)) {
        return true;
    }

    return false;
}

bool equal(int* src, int* dest) {
    //因为是hash的方式，将窗口内的字母计数存入数组，不确定窗口内的字符是a,还是z,就有可能hash在整个数组的任意位置。
    //所以我们要将src和dest整个空间进行比较，因为如果src和dest里面的字符相同(即使排序不同)，那么他们hash的结果必然相等。
    for (int i = 0; i < 26; i++) {
        if(src[i] != dest[i]) {
            return false;
        }
    }

    return true;
}