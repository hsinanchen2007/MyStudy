# @param {Integer} x
# @return {Integer}
def reverse(x)
    #将x转换为字符串然后进行切割为数组，每个数字为数组的一个元素
    #a=x.to_s.chars.map(&:to_i)
    a=x.to_s.split('')
    #return a
    c=['0','1']
    #将数组a合并为一个字符串并且转换类型为整数to_i；切割反转合并后b始终返回的是正数？？
    b=a.reverse.join.to_i
    #根据b的条件进行判断，然后返回
    if b>(2**31-1) || b<(-2**31)
        return 0
    elsif x>=0 and b <=(2**31-1) and b>=0
        return b
    elsif x< 0 and b <=(2**31-1) and b>=0
        return ~b+1   #当需要返回负数时，取b得补码+1 即得到负b
    end
end