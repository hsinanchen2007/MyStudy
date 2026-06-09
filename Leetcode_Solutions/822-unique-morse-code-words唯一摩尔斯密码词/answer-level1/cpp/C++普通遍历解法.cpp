```c++ 
       class Solution {
        public:
        int uniqueMorseRepresentations(vector<string>& words) {
          vector<string> cipher={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-        ","..-","...-",".--","-..-","-.--","--.."};
          set<string> result;
          for(int i=0;i<words.size();i++)
          {
              string s="";
              for(int j=0;j<words[i].size();j++)
              {
                    s+=cipher[words[i][j]-'a'];
              }
              result.insert(s);
          }
          return result.size();
        }
    };