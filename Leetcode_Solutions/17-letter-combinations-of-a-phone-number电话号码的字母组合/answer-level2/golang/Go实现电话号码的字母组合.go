

```golang
var digitMap = map[string]string{"2":"abc", "3":"def", "4":"ghi", "5":"jkl", 
	"6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}

func letterCombinations(digits string) []string {
    if len(digits)==0{
        return []string{}
    }
     res := []string{}
     strs := []rune(digits)
     st := []string{}
     for i:= 0;i<len(strs);i++{
        st = append(st,string(strs[i]))
     }
     process(st,0,"",&res)
     return res
}

func process(str []string,index int,path string,res *[]string){
    if index == len(str){
        *res = append(*res,path)
        return
    }
    letter := digitMap[str[index]]
    for i:=0;i<len(letter);i++{
        process(str,index+1,path+string(letter[i]),res)
    }
}

```