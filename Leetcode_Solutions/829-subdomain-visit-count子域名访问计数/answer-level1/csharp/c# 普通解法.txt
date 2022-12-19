### 解题思路
拆分，遍历，累加
因为含有“.”的域名信息里是后面的信息可以拆开而前面的信息无法拆开，所以采用倒序遍历

### 代码

```csharp
public class Solution {
    public IList<string> SubdomainVisits(string[] cpdomains) {
        Dictionary<string,int> temp=new Dictionary<string,int>();
        for(int i=0;i<cpdomains.Length;i++)
        {
            int count=Convert.ToInt32(cpdomains[i].Substring(0,cpdomains[i].IndexOf(' ')));
            string domin=cpdomains[i].Substring(cpdomains[i].IndexOf(' ')+1);
            
            string[] arr=domin.Split('.');
            string cur=string.Empty;
            for(int j=arr.Length-1;j>-1;j--)
            {
                if(cur.Length==0)
                {
                    cur=arr[j];
                }
                else
                {
                    cur=arr[j]+"."+cur;
                }

                if(temp.ContainsKey(cur))
                {
                    temp[cur]+=count;
                }
                else
                {
                    temp.Add(cur,count);
                }
            }
        }

        List<string> result=new List<string>();
        foreach(var item in temp)
        {
            result.Add(item.Value+" "+item.Key);
        }

        return result;
    }
}
```