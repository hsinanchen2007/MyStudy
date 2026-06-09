```
 string longestPalindrome(string s) {
        string str_result = "$#";
        for(int i = 0;i < s.length(); ++i){
            str_result += s[i];
            str_result += "#";
        }
        int max_mid_pos = 0;
        int max_length = 0;
        int mid_pos = 0;
        int last_right_max_pos = 0;
        vector<int> pb(str_result.length(),0);
        // 相对vector，使用 new int数组和malloc分配内存并不能节省内存消耗，有点奇怪，理论上vector会占用更大的内存
        //int* pb = new int[str_result.length()];
        //int * pb=(int*)malloc(sizeof(int)*str_result.length());
        for(int i = 1;i < str_result.length(); ++i){
            // if(last_right_max_pos > i) {
            //     if( pb[2*mid_pos - i] > last_right_max_pos - i) {
            //          pb[i] = last_right_max_pos - i;
            //     } else pb[i] = pb[2*mid_pos - i];
            // } else pb[i] = 1;
            // 使用 ? :三元运算符替代 if else，能降低一些执行用时
            pb[i] = last_right_max_pos > i ? (pb[2 * mid_pos - i] > last_right_max_pos - i ? last_right_max_pos - i : pb[2*mid_pos - i]) : 1;
            while(str_result[i + pb[i]] == str_result[i - pb[i]]) ++pb[i];
            if(last_right_max_pos -i < pb[i]) {
                last_right_max_pos = i + pb[i];
                mid_pos = i;
            }
            if(max_length < pb[i]) {
                max_length = pb[i];
                max_mid_pos = i;
            }
        }
        return s.substr((max_mid_pos - max_length) / 2,max_length - 1);
    }
```
__不知道leetcode这里的编译器是用什么来进行的，这里使用vector和new int数组、malloc分配内存比较，并不能节省内存消耗，有点奇怪，理论上vector会占用更大的内存__
