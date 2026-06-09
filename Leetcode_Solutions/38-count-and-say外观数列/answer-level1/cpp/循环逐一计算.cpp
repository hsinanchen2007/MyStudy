
从第一个开始逐一递推




            class Solution {
            public:
                string countAndSay(int n) {
                    if(n < 1 || n > 30)
                        return "";
                    string current,pre("1");
                    int index = 1;
                    while(index < n) {
                        current = pre;
                        pre.clear();
                        int count = 1;
                        for(int i = 0; i < current.size(); ++i) {
                            if(i+1 < current.size() && current[i] == current[i+1])
                                count++;
                            else {
                                pre.push_back(count+'0');
                                pre.push_back(current[i]);
                                count = 1;
                            }
                        }
                        ++index;
                    }
                    return pre;
                }
            };