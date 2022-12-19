    int repeatedStringMatch(string A, string B) {
        int len1 = A.length();
        int len2 = B.length();
        
        if(0 == len1 || 0 == len2)
            return 1;

        if(len1 > len2)
        {
            if(string::npos != A.find(B))
                return 1;
            else
            {
                //"aaaaaaaaaaaaaaaaaaaaaab"
                //"ba"
                string tmp = A;
                tmp += A;
                if(string::npos != tmp.find(B))
                    return 2;
                return -1;
            }
        }

        int count = len2/len1;
        if(len2 % len1 != 0)
            count += 1;
        string tmp;
        for(int j = 0; j <count; j++)
        {
            tmp = tmp + A;
        }
        
        if(string::npos != tmp.find(B))
        {
            return count;
        }
        else{
            tmp = tmp + A;
            if(string::npos != tmp.find(B))
                return count+1;
            return -1;
        }
    }