# @param {Integer[]} a
# @return {Integer[]}
def sorted_squares(a)
    a.map { |item| item * item }.sort
end