https://blog.csdn.net/us2019/article/details/105310248


        }```
        public static bool IsUnique(string astr)
        {
            bool b = true;
            HashSet<char> s = new HashSet<char>();
            for (int i = 0; i < astr.Length; i++)
            { 
                if (s.Contains(astr[i]))
                {
                    b = false;
                    break;
                }
                else
                {
                    s.Add(astr[i]);
                }
            }
            
            return b;
```
