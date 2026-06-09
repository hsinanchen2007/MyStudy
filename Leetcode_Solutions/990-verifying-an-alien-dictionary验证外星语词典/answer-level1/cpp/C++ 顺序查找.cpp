![360截图20200405232641145.jpg](https://pic.leetcode-cn.com/8427c5431312da17a1b24ac328cf897081d26a397a76d8c801ccd412665f7bd6-360%E6%88%AA%E5%9B%BE20200405232641145.jpg)

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n1 = words.size(); // n1=3
        //int n2 = order.size(); // n2=26
        int i = 1;
        for(;i<n1;i++) { //遍历words
            int first_len = words[i-1].length(); // first_len=4
            int second_len = words[i].length(); // second_len=5
            int firstindex=0,secondindex=0;
            while(firstindex <first_len && secondindex < second_len) {
                //firstindex = 3 secondindex =3
                if(order.find(words[i-1][firstindex]) < order.find(words[i][secondindex]))
                    break;
                else if(order.find(words[i-1][firstindex]) >
                        order.find(words[i][secondindex]))
                    return false;
                else {
                firstindex++;
                secondindex++;
                }
            }
            if(firstindex <first_len && secondindex == second_len)  return false;
            
        }
        return true;

    }
};