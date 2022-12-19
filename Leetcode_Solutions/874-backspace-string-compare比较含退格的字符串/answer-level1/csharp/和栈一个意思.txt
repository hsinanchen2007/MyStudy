 List<char> news = new List<char>();
            for(int i=0;i<S.Length;i++)
            {
               if(S[i]=='#' && news.Count>0)
                   news.RemoveAt(news.Count - 1);
               else if (S[i] != '#')
                   news.Add(S[i]);
            }
            List<char> newt = new List<char>();
            for (int i = 0; i < T.Length; i++)
            {
                if (T[i] == '#' && newt.Count > 0)
                    newt.RemoveAt(newt.Count - 1);
                else if (T[i] != '#')
                    newt.Add(T[i]);
            }
            return string.Join("",news) == string.Join("",newt);