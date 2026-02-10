x = list(input().split(' '))    
print(x[0], x[1:].count('O') + x[1:].count('△') + x[1:].count('X'))