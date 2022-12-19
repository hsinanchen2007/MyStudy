 string s = string.Join("/", nums);
            if (nums.Length <= 2) return s;
            s=s.Insert(s.IndexOf("/")+1, "(");
            s += ")";
            return s;