
document.addEventListener('DOMContentLoaded', () => {
    // Плавный скролл для якорных ссылок
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function (e) {
            e.preventDefault();
            const targetId = this.getAttribute('href');
            document.querySelector(targetId).scrollIntoView({
                behavior: 'smooth'
            });
        });
    });

    // Изменение хедера при скролле
    const header = document.querySelector('header');
    window.addEventListener('scroll', () => {
        if (window.scrollY > 50) {
            header.classList.add('scrolled');
        } else {
            header.classList.remove('scrolled');
        }
    });

    // Демонстрация голосового взаимодействия
    const demoMicBtn = document.getElementById('demo-mic-btn');
    const demoOutput = document.getElementById('demo-output');
    const demoMicIcon = demoMicBtn.querySelector('i');
    let isListening = false;

    demoMicBtn.addEventListener('click', () => {
        if (isListening) {
            isListening = false;
            demoMicBtn.classList.remove('listening');
            demoMicIcon.classList.remove('fa-microphone-alt-slash');
            demoMicIcon.classList.add('fa-microphone');
            demoOutput.textContent = "Обработка запроса...";

            setTimeout(() => {
                demoOutput.textContent = "Aqua: Здравствуйте! Чем могу помочь?";
            }, 2000);
        } else {
            isListening = true;
            demoMicBtn.classList.add('listening');
            demoMicIcon.classList.remove('fa-microphone');
            demoMicIcon.classList.add('fa-microphone-alt-slash');
            demoOutput.textContent = "Слушаю ваш запрос...";
        }
    });

    // Анимация текста при загрузке (для Hero Section)
    const heroTitle = document.querySelector('.hero-section h1');
    const heroSubtitle = document.querySelector('.hero-section .hero-subtitle');
    const heroBtn = document.querySelector('.hero-section .primary-btn');

    // Устанавливаем начальное состояние для анимации
    // Проверяем наличие элементов перед применением стилей
    if (heroTitle) { heroTitle.style.opacity = 0; }
    if (heroSubtitle) { heroSubtitle.style.opacity = 0; }
    if (heroBtn) { 
        heroBtn.style.opacity = 0; 
        heroBtn.style.transform = 'translateY(20px)';
    }

    setTimeout(() => {
        if (heroTitle) { 
            heroTitle.style.transition = 'opacity 1s ease-out';
            heroTitle.style.opacity = 1; 
        }
    }, 500);

    setTimeout(() => {
        if (heroSubtitle) {
            heroSubtitle.style.transition = 'opacity 1s ease-out';
            heroSubtitle.style.opacity = 1;
        }
    }, 1000);

    setTimeout(() => {
        if (heroBtn) {
            heroBtn.style.transition = 'opacity 1s ease-out, transform 1s ease-out';
            heroBtn.style.opacity = 1;
            heroBtn.style.transform = 'translateY(0)';
        }
    }, 1500);

    // --- Интерактивный курсор ---
    const customCursor = document.querySelector('.custom-cursor');
    let mouseX = 0;
    let mouseY = 0;
    let cursorX = 0;
    let cursorY = 0;
    const easing = 0.15; // Чем меньше значение, тем плавнее движение

    // Проверяем, что customCursor существует (т.е. мы не на мобильном устройстве)
    if (customCursor) {
        function animateCursor() {
            cursorX += (mouseX - cursorX) * easing;
            cursorY += (mouseY - cursorY) * easing;

            customCursor.style.left = `${cursorX}px`;
            customCursor.style.top = `${cursorY}px`;

            requestAnimationFrame(animateCursor);
        }

        document.addEventListener('mousemove', (e) => {
            mouseX = e.clientX;
            mouseY = e.clientY;
        });

        // Запускаем анимацию для кастомного курсора
        animateCursor();

        // Эффект курсора при наведении на интерактивные элементы
        // Добавлен 'tabindex="0"' для элементов, которые по умолчанию не фокусируются
        const interactiveElements = document.querySelectorAll('a, button, .feature-item, input, textarea');
        interactiveElements.forEach(el => {
            el.addEventListener('mouseenter', () => {
                customCursor.classList.add('active');
            });
            el.addEventListener('mouseleave', () => {
                customCursor.classList.remove('active');
            });
            // Для доступности с клавиатуры (tab)
            el.addEventListener('focus', () => {
                customCursor.classList.add('active');
            });
            el.addEventListener('blur', () => {
                customCursor.classList.remove('active');
            });
        });
    }


    // --- Автономный технологический фон: Генерация и анимация плавающих частиц ---
    const particlesContainer = document.querySelector('.floating-particles-container');
    const numberOfParticles = 40;

    for (let i = 0; i < numberOfParticles; i++) {
        const particle = document.createElement('div');
        particle.classList.add('floating-particle');

        const startX = Math.random() * window.innerWidth;
        const startY = Math.random() * window.innerHeight;
        particle.style.left = `${startX}px`;
        particle.style.top = `${startY}px`;

        const size = Math.random() * 4 + 2;
        particle.style.width = `${size}px`;
        particle.style.height = `${size}px`;

        const duration = Math.random() * 15 + 10;
        const delay = Math.random() * 15;
        const offsetX = (Math.random() - 0.5) * 200; // От -100 до 100px смещение по X
        const offsetY = (Math.random() - 0.5) * 200; // От -100 до 100px смещение по Y
        const scale = 0.8 + Math.random() * 0.4;
        const initialOpacity = Math.random() * 0.3 + 0.1;
        const peakOpacity = Math.random() * 0.4 + 0.5;

        particle.style.setProperty('--offset-x', `${offsetX}px`);
        particle.style.setProperty('--offset-y', `${offsetY}px`);
        particle.style.setProperty('--scale', scale);
        particle.style.setProperty('--initial-opacity', initialOpacity);
        particle.style.setProperty('--peak-opacity', peakOpacity);

        particle.style.animation = `float-particle ${duration}s infinite ease-in-out alternate forwards`;
        particle.style.animationDelay = `${delay}s`;
        
        particlesContainer.appendChild(particle);
    }
});
