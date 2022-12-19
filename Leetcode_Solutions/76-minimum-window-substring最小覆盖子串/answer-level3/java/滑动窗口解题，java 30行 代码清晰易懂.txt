![image.png](https://pic.leetcode-cn.com/5c48528065d495be37771fae3de5de09752bb30f5918a4d9f876f6d66175bb51-image.png)

- ### 思路:
    ```
    构建l,r两个指针组成滑动窗口
    1. r一直右移负责寻找符合条件的字串，不关心最小值问题
    2. 当找到符合条件的子串后，l开始右移缩小窗口范围，并记录最小字串，当缩小到子串不满足条件的时候，回到 1
    ```
- ### 优化点:
    ```
    1.  使用freq数组记录t内字母出现频率
        使用inT数组记录字母是否在t内
        引入这个inT 可能会增加空间开销，但是能使代码更易读
        更容易判断某个字母是否在t内，不需要关心和维护freq内其他非t字母的值
        当出现和t的字母重复的多余字母的时候，可以直接freq[sArr[r]] --,freq[sArr[r]] ++ 负数代表重复多余出现的次数
    2.  使用int型左右边界记录结果，比使用String型省去了subString的时间开销
    ```
- ### 代码:

    ```
    public String minWindow(String s, String t) {
        if(s == null || s.length() == 0 || t == null || t.length() == 0 ){
            return "";
        }
        int[] freq = new int[126];
        // 这里引入这个inT 可能会增加空间开销，但是能使代码更易读
        // 更容易判断某个字母是否在t内，不需要关心和维护freq内其他非t字母的值
        // 当出现和t的字母重复的多余字母的时候
        boolean[] inT = new boolean[126];  
        char[] sArr = s.toCharArray();
        int tLength = t.length();
        int minL = -s.length();
        int minR = 0;
        for (char c : t.toCharArray()) {
            freq[c]++;
            inT[c] = true;
        }
        // r负责找符合条件的字串,l负责找最短字串
        int l = 0,r = 0;
        for(;r < sArr.length;r++){ // 外层循环执行步骤1
            if(inT[sArr[r]] && freq[sArr[r]]-- > 0){ 
                tLength--; // tLength==0 表示找到符合条件的字串
                for(;tLength==0;l++){  // 内层循环执行步骤2
                    if(r-l < minR-minL){
                        minL = l;
                        minR = r;
                    }
                    if(inT[sArr[l]] && freq[sArr[l]]++ >= 0){ // 使得子串不满足条件
                        tLength++;
                    }
                }
            }
        }
        return minL < 0 ? "" : s.substring(minL,minR+1);
    }
    ```


