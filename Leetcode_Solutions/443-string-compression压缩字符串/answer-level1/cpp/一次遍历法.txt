    int compress(vector<char>& chars) {
        int len = chars.size();
        int indx = 0, i = 0, count = 0, anchor = 0;
        while(i < len)
        {
            if(chars[i] == chars[anchor])
            {
                i++;
                count++;
                continue;
            }
            chars[indx++] = chars[anchor];
            if(count > 1)
            {
                for( auto val: to_string(count))
                {
                    chars[indx++] = val;
                }
            }
            
            anchor = i;
            count = 0;
        }
        if(count == 0 && anchor == 0)
            return 0;

        chars[indx++] = chars[anchor];
        if(count > 1)
        {
            for( auto val: to_string(count))
            {
                chars[indx++] = val;
            }
        }
        return indx;

    }