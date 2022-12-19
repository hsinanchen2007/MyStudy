```
class Solution {
public:
    
    bool isPalindrome(string number)
    {
        if(number == "") return false;
        int i = 0, j = number.length()-1;
        while(i < j)
        {
            if(number[i] != number[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    long long stoll(string str)  
    {  
        long long result;  
        istringstream is(str);  
        is >> result;  
        return result;  
    }  
    
    string lltos(long long ll)  
    {  
        ostringstream os;  
        os<<ll;  
        string result;  
        istringstream is(os.str());  
        is>>result;  
        return result;  
    }  
    
    int superpalindromesInRange(string L, string R) {

        long long ll = stoll(L), rr = stoll(R);
        int MAGIC = 100000, cnt = 0;
        
        // count odd length;
        for (int k = 1; k < MAGIC; ++k) 
        {
            string s1 = to_string(k), s2 = "";
            for (int i = s1.length() - 2; i >= 0; --i)
            {
                s2 += s1[i];
            }
            long long v = stoll(s1+s2);
            v *= v;
            if (v > rr) break;
            if (v >= ll && isPalindrome(lltos(v))) 
            {
                cnt++;
            }
        }

        // count even length;
        for (int k = 1; k < MAGIC; ++k) 
        {
            string s1 = to_string(k), s2 = "";
            for (int i = s1.length() - 1; i >= 0; --i)
            {
                s2 += s1[i];
            }
            long long v = stoll(s1+s2);
            v *= v;
            if (v > rr) break;
            if (v >= ll && isPalindrome(lltos(v))) 
            {
                cnt++;
            }
        }

        return cnt;
    }
};
```