解题思路：
1.先check，保证输入满足条件
2.循环用J中的字符去查找S中匹配的字符数量，累加得到结果

public class Solution771
    {
        public int NumJewelsInStones(string J, string S)
        {
            //1.check
            //1.1 J 和 S 都为字母
            string isLetter = "[^a-zA-Z]+$";            
            if (System.Text.RegularExpressions.Regex.IsMatch(J,isLetter) && System.Text.RegularExpressions.Regex.IsMatch(S, isLetter))
            {
                Console.WriteLine("J 和 S 都必须为字母");
                return -1;
            }
            //1.2 S 和 J 最多含有50个字母
            if (J.Length > 50 || S.Length > 50)
            {
                Console.WriteLine("S 和 J 最多含有50个字母");
                return -1;
            }
            //1.3 J 中的字符不重复
            if (J.ToCharArray().Distinct().Count()!= J.Length)
            {
                Console.WriteLine("J 中的字符不重复");
                return -1;
            }


            int count = 0;
            //2.S匹配J中的字符
            foreach (var item in J)
            {
                List<char> charArr = S.ToList().FindAll(t => t == item);
                if (charArr!=null && charArr.Count>0)
                {
                    count += charArr.Count;
                }
            }

            return count;
        }
    }