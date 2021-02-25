import matplotlib.pyplot as plt
import pandas as pd

path = './planeta.csv'
columns=['x','y']
df=pd.read_csv('planeta.csv',names=columns)

fig = plt.figure()
plt.scatter(df.x[10],df.y[10],c='y',s=1)
plt.title(r'Central Force Law $F \sim \frac{1}{r^2}$')
plt.show()


opt=input('want to save the pic? Y/N ')

if opt.lower() == 'y':
    save_name=input('save pic with name (no include .png): ')
    save_name=save_name+'.png'
    fig.savefig(save_name)

