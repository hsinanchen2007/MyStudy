 public int StrStr(string haystack, string needle)
        {
            if (string.IsNullOrEmpty(needle))
            {
                return 0;
            }

            if (string.IsNullOrEmpty(haystack) || haystack.Length < needle.Length)
            {
                return -1;
            }
          
            var first = needle[0];
            var indexList = new List<int>();
            for (int i = 0; i < haystack.Length; i++)
            {
                if (haystack[i] == first)
                {
                    indexList.Add(i);
                }
            }

            if (indexList.Count > 0) // exist first character
            {
                foreach (var firstIndex in indexList)
                {
                    string subStr = "";
                    if (haystack.Length - firstIndex >= needle.Length)
                    {
                        subStr = haystack.Substring(firstIndex, needle.Length);
                        if (subStr == needle)
                        {
                            return firstIndex;
                        }
                    }
                }
            }

            return -1;
        }