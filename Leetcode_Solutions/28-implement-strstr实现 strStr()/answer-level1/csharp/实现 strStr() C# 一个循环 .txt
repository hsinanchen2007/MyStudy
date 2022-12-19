public class Solution {
    public int StrStr(string haystack, string needle) {
            if (string.IsNullOrEmpty(needle))
            {
                return 0;
            }

            if (string.IsNullOrEmpty(haystack) || haystack.Length < needle.Length)
            {
                return -1;
            }

            int start = 0;
            int end = needle.Length -1;
            while (start + needle.Length <= haystack.Length)
            {
                // from start to get subtre which length is needle's length
                if (haystack.Substring(start, needle.Length).Equals(needle))
                {
                    return start;
                }
                
                start++;
            }
            return -1;
    }
}