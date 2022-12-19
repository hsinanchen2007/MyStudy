```
class Solution {
public:
    string reverseWords(string s) {
		
		istringstream is(s);
        
        stack<string> st;

        string word, ret;

        while(is >> word)
        {
            st.push(word);
        }
		
		bool flag = false;
		
		while(st.size())
		{
			if(flag)
			{
				ret += " ";
			}
			else
			{
				flag = true;
			}

            ret += st.top();
            st.pop();
		}
		
		return ret;
    }
};
```
