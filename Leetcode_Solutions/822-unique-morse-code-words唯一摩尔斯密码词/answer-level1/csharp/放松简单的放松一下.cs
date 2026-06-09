 public static int UniqueMorseRepresentations(string[] words)
        {
            string[] pwd ={".-","-...","-.-.","-..",".","..-.","--.","....","..",
                             ".---","-.-",".-..","--","-.","---",".--.","--.-",
                             ".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
            List<string> lst = new List<string>();
            for(int i=0;i<words.Length;i++)
            {
                string tempstr = "";
                for (int j = 0; j < words[i].Length;j++)
                    tempstr += pwd[words[i][j] - 'a'];
                lst.Add(tempstr);
            }
            return lst.Distinct().Count();
        }