```
func intToRoman(num int) string {
    goal:=""
    copy:=num
    for copy !=0{
      if copy>=1000{
          copy=copy-1000
          goal+="M"
      }else if copy>=900{
          copy-=900
          goal+="CM"
      }else if copy>=500{
          copy-=500
          goal+="D"
      }else if copy>=400{
          copy-=400
          goal+="CD"
      }else if copy>=100{
          copy-=100
          goal+="C"
      }else if copy>=90{
          copy-=90
          goal+="XC"
      }else if copy>=50{
          copy-=50
          goal+="L"
      }else if copy>=40{
          copy-=40
          goal+="XL"
      }else if copy>=10{
          copy-=10
          goal+="X"
      }else if copy>=9{
          copy-=9
          goal+="IX"
      }else if copy>=5{
          copy-=5
          goal+="V"
      }else if copy>=4{
          copy-=4
          goal+="IV"
      }else if copy>=1{
          copy-=1
          goal+="I"
      } 
      }
    return goal
}
```
