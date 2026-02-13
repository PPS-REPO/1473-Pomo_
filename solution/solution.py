x = list(input().split(' '))    
print(x[0], x[1:].count('O') * 3 + x[1:].count('△') * 2 + x[1:].count('X') * 1)