## 🛠️ Manual do Usuário — **RYB DROP**

### 📘 Introdução

O **RYB DROP** é um sistema interativo de controle de LEDs desenvolvido para ambientes educacionais. Utilizando três botões e um LED RGB, o sistema permite que os alunos comuniquem suas necessidades ou sentimentos de maneira visual e discreta, contribuindo para um ambiente de aprendizado mais eficiente e empático.

---

### 🔧 Componentes

- 3 botões físicos (vermelho, amarelo e azul)  
- 1 LED RGB (vermelho, verde e azul)  
- 1 placa de desenvolvimento **Arduino**  
- 1 porta de carregamento **Micro-USB**  
- 1 bateria recarregável (7.4V)

---

### ✨ Funcionalidades

- **Botão Vermelho**: ao ser pressionado, o LED vermelho acende gradualmente, indicando que o aluno deseja sair da sala.  
- **Botão Amarelo**: ativa o LED amarelo, sinalizando que há ruído excessivo na sala. O LED permanece aceso até que o botão seja pressionado novamente.  
- **Botão Azul**: ao ser pressionado, o LED azul acende gradualmente, indicando que o aluno tem uma dúvida.  

---

### 🔌 Como Carregar

Para recarregar o dispositivo:  
1. Conecte um cabo Micro-USB a uma fonte de energia (como um carregador de celular).  
2. O sistema iniciará o carregamento automaticamente.

---

### ⚙️ Modo de Operação

1. Ao ligar o sistema, todos os LEDs permanecem desligados.  
2. Quando um botão é pressionado:
   - O LED correspondente à cor do botão é ativado.  
   - Os LEDs vermelho e azul acendem de forma gradual.  
   - O LED amarelo acende instantaneamente e permanece ligado até nova interação.  
3. Após a finalização do efeito de luz (ou nova pressão no botão, no caso do amarelo), o sistema retorna ao estado inicial.

---

### 🧩 Solução de Problemas

- **LEDs não acendem?**
  - Verifique as conexões entre os LEDs e a placa Arduino.
  - Certifique-se de que os botões estão funcionando corretamente.

- **Sistema não responde aos botões?**
  - Confira se o código está corretamente carregado na placa.
  - Certifique-se de que os pinos de entrada dos botões estão corretamente definidos no código.

---
