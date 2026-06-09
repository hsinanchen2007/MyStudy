
唯一的tip就是,使用了个total数组。
每次求max的时候，不用再关心，我是用的哪个位置的字符进行的替换，只需要确保，总数是够的就行。
例子：
babbbcbbbab
当index = 2, char c = 'b'的是否。
遍历到c，需要进行替换，index = 0有个b， cbbbab中也有好多个b。
其实是可以随意拿个b来进行替换，只需要保证，替换后的总count 小于 total就OK啦。


废话不多，直接上代码

`
public static int maxRepOpt1(String text) {

        int[] total = new int[26]; // 关键的地方。先记录下每个字母的出现次数
        char[] chars = text.toCharArray();
        for(char c: chars) {
            total[c-'a']++;
        }
        /** 声明一堆变量 */
        int index = 0; // 遍历用的游标
        int next = 1; // 下个窗口的起始位置
        int count = 1; // 窗口内计数
        boolean fake = false; // 是否替换了。
        int max = 0; // 结果
        char c = chars[0]; // 用于比较的char

        while(index<chars.length-1) { // 遍历到倒数第二个。
            
           if(c != chars[index+1]) { // 下一个char 是否与c 相同，相同的话，直接++。
               if(fake){ // 如果已经替换过了。那么就直接求Max，并重置所有变量
                    max = Math.max(max, Math.min(count, total[c-'a']));           
                    index = next;
                    count = 1;
                    c = chars[index];
                    fake = false;
               }else {
                    fake = true; // 标注替换。
                    next = index+1; // 记录下此窗口的开始的坐标。
                    count++;
                    index++;
               }
           }else {
               count++;
               index++;
           }
        }
        max = Math.max(max, Math.min(count, total[c-'a']));
        return max;
    }
`