import numpy as np; 
import pandas as pd
import cv2 as cv 
from PIL import Image as image

lista = list()
with open("teste.txt", "r") as documento: 

    for i in range (100): 
        dados = str(documento.readline())
        dados = dados[:-2]
        lista.append(dados.split(';'))

    documento.close()


array = np.array(lista, dtype=np.int32) * 7
img = image.fromarray(array)
img.show()