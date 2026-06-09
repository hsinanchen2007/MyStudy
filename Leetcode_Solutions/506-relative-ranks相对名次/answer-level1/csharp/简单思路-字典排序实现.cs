```
public string[] FindRelativeRanks(int[] nums) {
        var dict=new Dictionary<int,string>();
        var output=new string[nums.Length];
        for(var i=0;i<nums.Length;i++ ){
            dict[nums[i]]=string.Empty;
        }
        var t=dict.Keys.ToArray();
        Array.Sort(t);
        for(var i=0;i<t.Length;i++){
            var res=string.Empty;
            switch(i){
                case 0:
                    res="Gold Medal";
                    break;
                case 1:
                    res="Silver Medal";
                    break;
                case 2:
                    res="Bronze Medal";
                    break;
                default:
                    res=(i+1).ToString();
                    break;
            }
            dict[t[t.Length-1-i]]=res;
        }
        for(var i=0;i<nums.Length;i++ ){
            output[i]=dict[nums[i]];
        }
        return output;
    }
```
