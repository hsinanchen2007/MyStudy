![Capture.PNG](https://pic.leetcode-cn.com/dcbb9e7356548aa8c18ddc025b82837be0df48af8b80b0387b8a07e0da6e523f-Capture.PNG)

```
vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        for(auto str:words)
        {
            int num1=0,num2=0,num3=0;
            for(auto c:str)
            {
                switch(c)
                {
                case 'Q':
                case 'q':
                case 'w':
                case 'W':
                case 'e':
                case 'E':
                case 'r':
                case 'R':
                case 't':
                case 'T':
                case 'Y':
                case 'y':
                case 'U':
                case 'u':
                case 'I':
                case 'i':
                case 'o':
                case 'O':
                case 'p':
                case 'P':
                num1=1;
                break;
                case 'a':
                case 's':
                case 'S':
                case 'd':
                case 'D':
                case 'f':
                case 'F':
                case 'g':
                case 'G':
                case 'H':
                case 'h':
                case 'J':
                case 'j':
                case 'K':
                case 'k':
                case 'L':
                case 'l':
                case 'A':
                num2=1;
                break;
                case 'Z':
                case 'z':
                case 'x':
                case 'X':
                case 'c':
                case 'C':
                case 'v':
                case 'V':
                case 'b':
                case 'B':
                case 'n':
                case 'N':
                case 'm':
                case 'M':
                num3=1;
                break;
                default:
                break;
                }
            }
            if(num1+num2+num3<2)
                ret.push_back(str);
        }
        return ret;
    }

```
