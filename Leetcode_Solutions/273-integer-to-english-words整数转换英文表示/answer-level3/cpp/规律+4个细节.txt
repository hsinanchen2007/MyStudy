/**
 * 1>字符串是从左到右  ————》  而不是右到左
 * 2>除法乘法优先级一样
 * 3>类外只能定义，不能跑程序 所以刚刚for就一直报错
 * 4>细节多多，在转化英文时【0，999】
 * 我的思路是：     
 * 如果大于99 ——————说明会带hundred这个英文  这时候搞定百位，通过%100取得后两位的数   后面两个数就是下面相同的操作         
            * 【【【【！！细节2  100是 one hundred  而不是one hundred zero                                                                                                                            
            * 处理：当搞定百位，后两位如果00 就可以结束了。】】】】
            * 
            * 【【【【细节3 是每3位每3位取的对吧，如果100 000  这种呢
            * 程序还是会将前面处理成one hundred 后面处理成zero
            * 处理：可以发现zero只是一开始有用 意思就是000才会翻译成zero  而101则会翻译成one hundred one。   那么我就可以  如果翻译出来的是zero 且ans非空 就可以跳过了】】】
            * 
            * 【细节4 空格问题，只在确定的位置加“ ”，不要预先为后面添加， 以及ans一开始空就不用加了】
            * 
            * 
 *   else if       【0，19】 ——————就直接输出存在hash表的英文
 *   else           【20，99】——————得先取出十位  再加上个位   比如99 ninety nine                           ！！细节1  20是twenty   ！而不是twenty zero！
 */
```
class Solution {
public:
    unordered_map<int, string> hash;
    //为了更快，用了unordered_map 但就不方便用重载的【】赋值
    string n1[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string n2[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    int hundred = 100, thousand = 1000, million = 1000000, billion = 1000000000;
    
    //以上是复制大佬的
    
    
    string translate_three(string tmp) {
        /*将 【0，999】范围转化成英文字符串*/
        int k = atoi(tmp.c_str());
        if (k >= 100) {//一定带hundred
            string res = "";
            res += hash[k / 100] + " " +  hash[hundred];//取百位 不能预先在后面加“ ” 可能900
            k %= 100;//技巧：取后两位
            if (k == 0)//后面是0就没必要搞了 如100
                return res;
            
            else if (k <= 19) {//【1，19】
                res += " " + hash[k];
            }
            else {
                //res += " " + hash[k / 10 * 10] + " " + hash[k % 10];
                if (k % 10 == 0)//看个位是不是0  处理120这种情况 不加多一个zero
                    res += " " + hash[k / 10 * 10];
                else
                    res += " " + hash[k / 10 * 10] + " " + hash[k % 10];
            }
            return res;
        }
        else if (k <= 19) {
            return hash[k];
        }
        else { //【20， 99】
            //return hash[k / 10 * 10] + " " + (k % 10 == 0)? "" : hash[k % 10];//除10再*10是为了将23变20  除法乘法优先级一样
            if (k % 10 == 0)
                return hash[k / 10 * 10];
            else
                return hash[k / 10 * 10] + " " + hash[k % 10];
        }
    }
    
    string numberToWords(int num) {
        //用循环方便写，好过你一个个手写
        for (int i = 0; i < 20; ++i)
            hash[i] = n1[i];
        for (int i = 20, j = 0; i < 100; i += 10, j++)  
            hash[i] = n2[j];
        
        hash[hundred] = "Hundred", hash[thousand] = "Thousand";
        hash[million] = "Million", hash[billion] = "Billion";
        
        
        string s_num = to_string(num), tmp, ans = "";
        int wei = s_num.size();//wei位

        int i = 0, j = wei - 1;
        while (i < wei) {
            string tmp = "";
            do {
                tmp += s_num[i];
                i++;
                j--;
            }while ((j + 1) % 3 != 0);//最多10位 即【0，9】  而我们习惯从右当0，这样一来用j表示：从右到这是第几位，【9】 【8 7 6】 【5 4 3】 【2 1 0】  可以发现都是取到3的倍数
            string hou;
            if (j + 1 == 9)
                hou = " " + hash[billion];
            else if (j + 1 == 6)
                hou = " " + hash[million];
            else if (j + 1 == 3)
                hou = " " + hash[thousand];
            else
                hou = "";


            string wtf = translate_three(tmp);
            if (ans != "" && wtf =="Zero")//处理100 000的情况
                continue;
            else {
                if (ans != "")
                    ans += " ";
            }
                
            ans += translate_three(tmp) + hou;
        }
        return ans;
    }
};
```

