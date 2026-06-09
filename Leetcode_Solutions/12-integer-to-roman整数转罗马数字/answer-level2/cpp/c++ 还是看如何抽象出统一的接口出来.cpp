### 解题思路
此处撰写解题思路

### 代码

```cpp
// class Solution {
// public:
//     string process_thousand(int k){
//         if(k == 0) return "";
//         string res;
//         for(int i = 0; i < k; i++){
//             res.push_back('M');
//         }
//         return res;
//     }

//     string process_hundurd(int k){
//         if(k == 0) return "";
//         string res;
//         if(k == 4) return "CD";
//         if(k == 9) return "CM";
//         if(k < 4){
//             for(int i = 0; i < k; i++) res.push_back('C');
//         }else if(k < 9){
//             res.push_back('D');
//             for(int i = 5; i < k; i++){
//                 res.push_back('C');
//             }
//         }
//         return res;
//     }

//     string process_ten(int k){
//         if(k == 0) return "";
//         string res;
//         if(k == 4) return "XL";
//         if(k == 9) return "XC";
//         if(k < 4){
//             for(int i = 0; i < k; i++) res.push_back('X');
//         }else if(k < 9){
//             res.push_back('L');
//             for(int i = 5; i < k; i++){
//                 res.push_back('X');
//             }
//         }
//         return res;
//     }

//     string process_single(int k){
//         if(k == 0) return "";
//         string res;
//         if(k == 4) return "IV";
//         if(k == 9) return "IX";
//         if(k < 4){
//             for(int i = 0; i < k; i++) res.push_back('I');
//         }else if(k < 9){
//             res.push_back('V');
//             for(int i = 5; i < k; i++){
//                 res.push_back('I');
//             }
//         }
//         return res;
//     }
//     string intToRoman(int num) {
//         vector<int> nums(4, 0);
//         int cnt = 3;
//         while(num > 0){
//             nums[cnt--] = num % 10;
//             num /= 10;
//         }
//         string res;
//         res += process_thousand(nums[0]);
//         res += process_hundurd(nums[1]);
//         res += process_ten(nums[2]);
//         res += process_single(nums[3]);
//         return res;
//     }
// };

class Solution {
public:
    string process(int k, char a1, char a5, char next){
        if(k == 0) return "";
        string res;
        if(k == 4){
            res.push_back(a1);
            res.push_back(a5);
        }else if(k == 9){
            res.push_back(a1);
            res.push_back(next);
        }else if(k < 4){
            for(int i = 0; i < k; i++) res.push_back(a1);
        }else if(k < 9){
            res.push_back(a5);
            for(int i = 5; i < k; i++){
                res.push_back(a1);
            }
        }
        return res;
    }
    string intToRoman(int num) {
        vector<vector<char>> hash{{'M', '#', '#'}, {'C', 'D', 'M'}, {'X', 'L', 'C'}, {'I', 'V', 'X'}};
        vector<int> nums(4, 0);
        int cnt = 3;
        while(num > 0){
            nums[cnt--] = num % 10;
            num /= 10;
        }
        string res;
        for(int i = 0; i < 4; i++){
            res += process(nums[i], hash[i][0], hash[i][1], hash[i][2]);
        }
        return res;
    }
};
```