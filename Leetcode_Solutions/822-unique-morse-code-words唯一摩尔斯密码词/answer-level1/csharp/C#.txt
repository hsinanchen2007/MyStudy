
//递归
public class Solution {
    public int UniqueMorseRepresentations(string[] words) {
        if (words.Count() == 0)
            {
                return 0;
            }
        if (words.Count() == 1)
            {
                return 1;
            }
        Dictionary<string, string> MorseCode = new Dictionary<string, string>() { {"a",".- " },{"b","-..." },{ "c", "-.-." },{ "d", "-.." }, { "e", "." }, { "f", "..-." }, { "g", "--." }, { "h", "...." },
                { "i", ".." }, { "j", ".---" }, { "k", "-.-" }, { "l", ".-.." }, { "m", "--" }, { "n", "-." }, { "o", "---" }, { "p", ".--." }, { "q", "--.-" }, { "r", ".-." }, { "s", "..." }, { "t", "-" },
                { "u", "..-" }, { "v", "...-" }, { "w", ".--" }, { "x", "-..-" }, { "y", "-.--" }, { "z", "--.." } };
            List<string> morseList = new List<string>();
            foreach (string w in words)
            {
                StringBuilder code = new StringBuilder();
                foreach (char wChar in w)
                {
                    code.Append(MorseCode[wChar.ToString()].ToString().Trim());
                }
                morseList.Add(code.ToString());
            }
            return morse(morseList, 0, 1).Count();
    }
    
    public List<string> morse(List<string> morseList,int index,int newIndex)
        {
            if (morseList[index].ToString() == morseList[newIndex].ToString())
            {
                morseList.RemoveAt(newIndex);
                if (newIndex > morseList.Count - 1)
                {
                    index++;
                    newIndex = index + 1;
                    if (index > morseList.Count - 1)
                    {
                        return morseList;
                    }
                    else
                    {
                        morseList = morse(morseList, index, newIndex);
                    }
                }
                else
                {
                    morseList = morse(morseList, index, newIndex);
                }
            }
            else
            {
                if (newIndex == morseList.Count-1)
                {
                    index++;
                    newIndex = index+1;
                    if (index >= morseList.Count - 1)
                    {
                        return morseList;
                    }
                    else
                    {
                        morseList = morse(morseList, index, newIndex);
                    }
                }
                else
                {
                    newIndex++;
                    morseList = morse(morseList, index, newIndex);
                }
            }
            return morseList;
        }
}


//遍历
public int UniqueMorseRepresentations(string[] words) {
        if (words.Count() == 0)
            {
                return 0;
            }
            if (words.Count() == 1)
            {
                return 1;
            }
            Dictionary<string, string> MorseCode = new Dictionary<string, string>() { {"a",".- " },{"b","-..." },{ "c", "-.-." },{ "d", "-.." }, { "e", "." }, { "f", "..-." }, { "g", "--." }, { "h", "...." },
                { "i", ".." }, { "j", ".---" }, { "k", "-.-" }, { "l", ".-.." }, { "m", "--" }, { "n", "-." }, { "o", "---" }, { "p", ".--." }, { "q", "--.-" }, { "r", ".-." }, { "s", "..." }, { "t", "-" },
                { "u", "..-" }, { "v", "...-" }, { "w", ".--" }, { "x", "-..-" }, { "y", "-.--" }, { "z", "--.." } };
            List<string> morseList = new List<string>();
            foreach (string w in words)
            {
                StringBuilder code = new StringBuilder();
                foreach (char wChar in w.Trim())
                {
                    code.Append(MorseCode[wChar.ToString()].ToString().Trim());
                }
                bool ok = true;
                foreach (string s in morseList)
                {
                    if (s == code.ToString())
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    morseList.Add(code.ToString());
                }
            }
            return morseList.Count();
    }

