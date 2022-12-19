很简单的循环遍历：
```c# []
public int UniqueMorseRepresentations(string[] words) {
        var dict=new Dictionary<string,int>();
        var mose=new string[26] {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        var sb=new StringBuilder();
        foreach(var item in words){
            sb.Clear();
            foreach(var c in item){
                sb.Append(mose[c-'a']);
            }
            
            var newStr=sb.ToString();
            if(!dict.ContainsKey(newStr)){
                dict[newStr]=0;
            }
        }
        return dict.Keys.Count;
    }
```

