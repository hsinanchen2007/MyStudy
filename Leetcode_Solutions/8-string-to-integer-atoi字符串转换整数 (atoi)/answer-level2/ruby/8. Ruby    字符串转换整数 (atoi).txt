# @param {String} str
# @return {Integer}
def my_atoi(str)
    #删除头部空白字符
    str=str.lstrip
    a=[]
    if str[0]=='-' || str[0]=='+'
       a.push(str[0])
        for i in 1...str.length
            if str[i].to_i.to_s==str[i]   #判断str[i]是否为数字
                a.push(str[i])
            elsif str[i].to_i.to_s!=str[i]
                break
            end
        end
        b=a.join.to_i   #将数组a合并为字符串并将类型转换为整数 to_i，判断b的范围，根据情况输出
        if b>(2**31-1) 
            b= (2**31-1) 
        elsif b<(-2**31)   
            b=(-2**31) 
        else 
            b=b
        end
    elsif str[0].to_i.to_s!=str[0] && str[0]!='-' && str[0]!='+'
        b=0
    elsif str[0].to_i.to_s==str[0]
        for i in 0...str.length
            if str[i].to_i.to_s==str[i]
                a.push(str[i])
            elsif str[i].to_i.to_s!=str[i]
                break
            end
        end
        b= a.join.to_i
        if b>(2**31-1) 
            b= (2**31-1) 
        elsif b<(-2**31)   
            b=(-2**31) 
        else 
            b=b
        end
    end
    return b
end