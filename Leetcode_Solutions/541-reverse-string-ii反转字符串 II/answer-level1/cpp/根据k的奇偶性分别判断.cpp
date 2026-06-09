    public:
    string reverseStr(string s, int k) {
        int count = 0, yu = 0, len = s.length();
        if(0 == len || 0 == k)
            return s;
        count  = len/k;
        yu = len%k;
        for(int i = 0; i < count; i++)
        {
            if(i%2 == 0)
            {
                int start = i*k;
                int end = (i+1)*k;
                reverse(s.begin()+start, s.begin()+end);
            }
        }
        if(0 != yu && count%2 == 0)
            reverse(s.begin()+k*count, s.end());
        return s;
    }