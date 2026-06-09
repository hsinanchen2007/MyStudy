### 解题思路
此处撰写解题思路

### 代码

```cpp
template<class T> 
ostream & operator<<(ostream & os , vector<T> vec){
    cout<<"[";
    for (int i = 0 ; i < vec.size()-1 ; ++i ){
        cout<<vec[i]<<",";
    }
    cout<<vec[vec.size()-1]<<"]";
    return os;
}
class Solution {
public:

    int expressiveWords(string S, vector<string>& words) {
        vector<char> ch;
        vector<int>  ch_nums;
        char cc = S[0];
        char cc_cnt = 1 ;
        for (int i = 1 ; i< S.size() ; ++i){
            char c = S[i];
            if ( c == cc ) ++cc_cnt;
            else {
                ch.push_back(cc);
                ch_nums.push_back(cc_cnt);
                cc_cnt=1;
                cc = c;
            }
        }
        ch.push_back(cc);
        ch_nums.push_back(cc_cnt);
        cout<< ch <<endl;
        cout<< ch_nums<<endl;
        int word_cnt=0 ;
        for(auto str : words){
            char cc = str[0];
            char cc_cnt = 1 ;
            int char_idx=0;
            bool equal=true;
            for (int i = 1 ; i<str.size() ; ++i){
                char c =str[i];
                if ( c == cc ) ++cc_cnt;
                else {
                    if (cc != ch[char_idx] || (cc_cnt > ch_nums[char_idx]) || (cc_cnt < ch_nums[char_idx] && ch_nums[char_idx] < 3))  {
                        equal=false;
                        break;
                    }
                    char_idx++;
                    cc_cnt=1;
                    cc = c;
                }
        }
        //if (cc != ch[char_idx] || (cc_cnt > ch_nums[char_idx]) || (cc_cnt < ch_nums[char_idx] && ch_nums[char_idx] < 3) )  equal=false;
        if (cc != ch[char_idx] || (cc_cnt > ch_nums[char_idx]) || (cc_cnt < ch_nums[char_idx] && ch_nums[char_idx] < 3) || char_idx < ch.size()-1)  equal=false;
            if( equal ) word_cnt++;
            
        }
        
        return word_cnt;
    }
};
```