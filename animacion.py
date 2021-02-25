# Planet Ploting simulation from Discret Element Method (DEM)

import matplotlib.pyplot as plt
import matplotlib
import matplotlib.animation as animation
import pandas as pd
import numpy as np


# Data
path = './planeta.csv'
columns=['x','y']
df=pd.read_csv('planeta.csv',names=columns)
n= int(len(df.x))
# print(n)

# to plot
x, y = [], []
for i in range(len(df)):
    if i%100==0:
        x.append(df.x[i])
        y.append(df.y[i])

style='seaborn-dark-palette'
plt.style.use(style)

# Figure
fig = plt.figure()
def update(curr):
    if curr == n:
        a.event_source.stop()
    plt.cla()
    plt.scatter(x[curr],y[curr],c='k',s=100)
    plt.scatter(x,y,c='y',s=0.4,alpha=0.2)
    plt.scatter(0,0,c='y',s=500)
    plt.axis([-13,13,-13,13])
    plt.gca().set_ylabel('y coord.')
    plt.gca().set_xlabel('x coord.')
    plt.gca().set_title(r'Gravitational attraction force $F \propto \frac{1}{r^2}$')
    plt.annotate('current coordinates : ({:.2f},{:.2f})'.format(x[curr],y[curr]),xy=[-7,11])
    return fig,

a = animation.FuncAnimation(fig,func=update,interval=100,repeat=False) # animation class instance
plt.show()

# To save
# writer = animation.PillowWriter(fps=100)
# a.save("animation.gif", writer=writer)
