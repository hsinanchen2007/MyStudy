class Solution {
public:

    bool is_ok(char ch){
	    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
		    return true;
	    return false;
    }

    string reverseVowels(string s) {
        //这题照样可以使用双指针法
        if(s.size()<=0) return s;

        int left=0,right=s.size()-1;
        while(left<right){
            //两个找元音字母的while判断条件是<，那么不论过了几轮，最后一轮left=right
            //所以相等的那个位置无论是不是元音字母都会自己和自己交换一次，然后left>right就退出了外面的循环
            while(!is_ok(s[left]) && left<right){
                //找到左边第一个元音字母
                left++;
            }
            while(!is_ok(s[right]) && left<right){
                //找到右边第一个元音字母
                right--;
            }
            //然后进行交换
            swap(s[left],s[right]);
            //交换完了，这两个位置就处理完了，分别前进。
            left++;
            right--;
        }
        return s;
    }
};