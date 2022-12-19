public  bool IsValid(string s)
        {
            if (s.Contains("()") || s.Contains("[]") || s.Contains("{}") || s.Contains(" "))
            {
                string news = s.Replace("()", "").Replace("[]", "").Replace("{}", "").Replace(" ", "");
                return IsValid(news);
            }
            else
            {
                return s.Length > 0 ? false : true;
            }
        }