刚刚入门上手c++，加油！（还是python方便啊...）
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int num = 0;
        for (int i = 0; i < 3; i++ ){
            num += (guess[i] == answer[i]);
        } 
        return num;
    }
};